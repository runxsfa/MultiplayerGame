#include "Character/NotifyStateRightWeapon.h"

void UNotifyStateRightWeapon::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp && MeshComp->GetOwner())
	{
		MannyCharacter = Cast<AMannyCharacter>(MeshComp->GetOwner());
		if (MannyCharacter)
		{
			MannyCharacter->ActivateRightWeapon();
		}
	}
}

void UNotifyStateRightWeapon::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp && MeshComp->GetOwner())
	{
		if (MannyCharacter)
		{
			MannyCharacter->DeactivateRightWeapon();
		}
	}
}