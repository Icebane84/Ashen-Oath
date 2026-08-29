// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenMartialStanceBalanceDataAsset.generated.h"

/**
 * UAshenMartialStanceBalanceDataAsset
 * 
 * Primary Data Asset enabling live, safe balance tweaking of Kaelen's 4 martial stances
 * (Vom Tag, Pflug, Ochs, Mordhau) in the Unreal Editor without recompilation.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenMartialStanceBalanceDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UAshenMartialStanceBalanceDataAsset();

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId(TEXT("AshenMartialStanceBalanceDataAsset"), GetFName());
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stance Balance | Vom Tag (High Wrath)", meta = (DisplayName = "Vom Tag Kinematics"))
	FOathbringerStanceKinematics VomTagConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stance Balance | Pflug (Low Plow)", meta = (DisplayName = "Pflug Kinematics"))
	FOathbringerStanceKinematics PflugConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stance Balance | Ochs (Crown Guard)", meta = (DisplayName = "Ochs Kinematics"))
	FOathbringerStanceKinematics OchsConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stance Balance | Mordhau (Half-Sword)", meta = (DisplayName = "Mordhau Kinematics"))
	FOathbringerStanceKinematics MordhauConfig;

	/** Retrieves and safely clamps stance kinematics for the given martial stance */
	UFUNCTION(BlueprintPure, Category = "Ashen|Balance")
	FOathbringerStanceKinematics GetKinematicsForStance(EOathbringerMartialStance Stance) const;
};
