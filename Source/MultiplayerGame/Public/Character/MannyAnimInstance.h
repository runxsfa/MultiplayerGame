// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MannyAnimInstance.generated.h"


// Declarations
class AMannyCharacter;
/**
 * 
 */
UCLASS()
class MULTIPLAYERGAME_API UMannyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	// Used in animation blueprint
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);

	// We can initialize our variables and be able to use them in BP
	virtual void NativeInitializeAnimation() override;


private:

	// Create variable to have reference to Manny character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	AMannyCharacter* MannyCharacter;

	// Speed of Manny
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float Speed;

	// True or false if player is in the air
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	bool bIsInAir;

	// Movement offset yaw to be used in anim instance blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float MovementOffsetYaw;
};
