// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/AshenAlchemicalCraftingTypes.h"
#include "AshenAlchemicalMasterBridge.generated.h"

/**
 * UAshenAlchemicalMasterBridge
 * Master domain bridge broadcasting alchemical crafting events, trap activations, and campfire rest state transitions across subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bAlchemicalBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastRecipeCrafted(EAlchemicalItemType ItemType, int32 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastTripwireTriggered(const FVector& TrapLocation);
};
