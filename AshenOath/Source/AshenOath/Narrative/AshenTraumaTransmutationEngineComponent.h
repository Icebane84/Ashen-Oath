// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "AshenTraumaTransmutationEngineComponent.generated.h"

/**
 * UAshenTraumaTransmutationEngineComponent
 * 
 * Forges permanent trait rewards from transmuted combat trauma debt.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraumaTransmutationEngineComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTraumaTransmutationEngineComponent();

	/** Forges a new permanent trait reward */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Narrative|Hearth")
	FTransmutedTraitReward ForgeTrait(FName TraitName, FGameplayTag TraitTag, float Bonus);

	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Hearth")
	int32 GetUnlockedTraitsCount() const { return UnlockedTraits.Num(); }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Narrative|Hearth")
	TArray<FTransmutedTraitReward> UnlockedTraits;
};
