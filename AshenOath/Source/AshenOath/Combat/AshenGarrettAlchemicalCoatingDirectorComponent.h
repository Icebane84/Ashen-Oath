// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenGarrettAlchemicalCoatingDirectorComponent.generated.h"

/**
 * UAshenGarrettAlchemicalCoatingDirectorComponent
 * 
 * Manages Garrett's inventory of craftable alchemical flasks (Naphtha, Frost Resin, Vitriol Acid, Copper Salve).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettAlchemicalCoatingDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettAlchemicalCoatingDirectorComponent();

	/** Gets available flask count for coating */
	UFUNCTION(BlueprintPure, Category = "Ashen|AlchemicalSlag|Garrett")
	int32 GetFlaskCount(EAlchemicalBladeCoating Coating) const;

	/** Consumes one flask to apply to weapon */
	UFUNCTION(BlueprintCallable, Category = "Ashen|AlchemicalSlag|Garrett")
	bool ConsumeFlask(EAlchemicalBladeCoating Coating);

	/** Adds brewed flasks at campfire */
	UFUNCTION(BlueprintCallable, Category = "Ashen|AlchemicalSlag|Garrett")
	void AddBrewedFlasks(EAlchemicalBladeCoating Coating, int32 Amount);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|AlchemicalSlag|Garrett")
	TMap<EAlchemicalBladeCoating, int32> FlaskInventory;
};
