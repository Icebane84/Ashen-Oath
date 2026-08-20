// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AshenInteractableInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UAshenInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * IAshenInteractableInterface
 * Standardized interaction interface for world objects (chests, doors, levers, sanctuaries).
 */
class ASHENOATH_API IAshenInteractableInterface
{
	GENERATED_BODY()

public:
	/** Trigger interaction with the player */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AshenOath|Interactable")
	void Interact(APawn* Player);

	/** Retrieve the text prompt displayed to the player */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AshenOath|Interactable")
	FString GetInteractionText() const;
};
