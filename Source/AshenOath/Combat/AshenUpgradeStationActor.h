// AshenUpgradeStationActor.h
// Copyright Ashen Oath. All rights reserved.
// PHOENIX CODEX: ENGINE-SPEC-001 (DEFINITIVE CANON) & Pillar III
// Permanent Ash upgrade vendor placed at Heartstone Sanctuaries.
#pragma once

#include "CoreMinimal.h"
#include "AshenInteractableActor.h"
#include "AshenUpgradeStationActor.generated.h"

USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenUpgradeRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade")
	FName UpgradeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade")
	FText UpgradeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade")
	float AshCost = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade")
	bool bPurchased = false;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpgradePurchasedSignature, const FAshenUpgradeRecord&, Upgrade);

/**
 * @class AAshenUpgradeStationActor
 * @brief Heartstone upgrade vendor allowing players to spend Ash for permanent unlocks.
 */
UCLASS()
class ASHENOATH_API AAshenUpgradeStationActor : public AAshenInteractableActor
{
	GENERATED_BODY()

public:
	AAshenUpgradeStationActor();

	/** Attempt to purchase an upgrade using Ash currency. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Upgrade")
	bool PurchaseUpgrade(AActor* Interactor, FName UpgradeID);

	/** Access available upgrades. */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Upgrade")
	const TArray<FAshenUpgradeRecord>& GetAvailableUpgrades() const { return Upgrades; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Upgrade|Events")
	FOnUpgradePurchasedSignature OnUpgradePurchased;

protected:
	virtual void Interact_Implementation(APawn* Player) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Upgrade")
	TArray<FAshenUpgradeRecord> Upgrades;
};

