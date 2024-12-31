#pragma once

#include "CoreMinimal.h"
#include "MannyCharacter.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "NotifyStateRightWeapon.generated.h"

// Declarations
class AMannyCharacter;

/**
 *
 */
UCLASS()
class MULTIPLAYERGAME_API UNotifyStateRightWeapon : public UAnimNotifyState
{
	GENERATED_BODY()

public:

	UPROPERTY()
	AMannyCharacter* MannyCharacter;

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};