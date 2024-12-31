// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MannyAnimInstance.h"

#include "Character/MannyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Acts like tick for animation. Get speed.
void UMannyAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (MannyCharacter == nullptr)
	{
		MannyCharacter = Cast<AMannyCharacter>(TryGetPawnOwner());
	}

	if (MannyCharacter)
	{
		// Get speed of Wukong from velocity
		FVector Velocity{ MannyCharacter->GetVelocity() };
		Velocity.Z = 0;
		Speed = Velocity.Size();

		// Is the player in the air
		bIsInAir = MannyCharacter->GetCharacterMovement()->IsFalling();

		// Get offset yaw to player in blend spaces
		FRotator const AimRotation = MannyCharacter->GetBaseAimRotation();
		FRotator const MovementRotation = UKismetMathLibrary::MakeRotFromX(MannyCharacter->GetVelocity());

		MovementOffsetYaw = UKismetMathLibrary::NormalizedDeltaRotator(MovementRotation, AimRotation).Yaw;
	}
}

// Acts like begin play create reference to Manny Character
void UMannyAnimInstance::NativeInitializeAnimation()
{
	MannyCharacter = Cast<AMannyCharacter>(TryGetPawnOwner());
}