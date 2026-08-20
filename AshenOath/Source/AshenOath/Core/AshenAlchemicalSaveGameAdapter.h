// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalFormulationTypes.h"
#include "AshenAlchemicalSaveGameAdapter.generated.h"

/**
 * UAshenAlchemicalSaveGameAdapter
 * Serializes Garrett's alchemical reagent inventory, crafted pouches, and recipe unlock states.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveAlchemicalInventory(const FAlchemicalInventoryPouch& Pouch);
};
