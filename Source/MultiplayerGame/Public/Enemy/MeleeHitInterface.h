#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MeleeHitInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMeleeHitInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class MULTIPLAYERGAME_API IMeleeHitInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void MeleeHIt(FHitResult HitResult);
};