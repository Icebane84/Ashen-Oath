// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/AshenAlchemicalCraftingTypes.h"
#include "AshenAlchemicalCompanionAdapter.generated.h"

/**
 * UAshenAlchemicalCompanionAdapter
 * Manages Garrett's tactical assist behaviors during combat (auto-deploying tripwires when Kaelen is flanked) and campfire rest synergy.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalCompanionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalCompanionAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	bool ShouldGarrettDeployAssistTrap(float GarrettTrust, bool bIsPlayerFlanked) const;
};
