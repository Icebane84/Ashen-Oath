// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenDevilsBargainTransformationSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDevilsBargainAcceptedSignature, float, AttackSpeedMultiplier, float, TrustAtrophyPenalty, float, SpiritualStainPercent);

/**
 * UAshenDevilsBargainTransformationSubsystem
 *
 * Subsystem for Dark Mode / Unchained Berserk transformation (The Devil's Bargain, PRS-001 Combat Blueprint).
 */
UCLASS()
class ASHENOATH_API UAshenDevilsBargainTransformationSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|DevilsBargain")
	void AcceptDevilsBargain();

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|DevilsBargain|Events")
	FOnDevilsBargainAcceptedSignature OnBargainAccepted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|DevilsBargain")
	bool bIsUnchainedBerserkActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|DevilsBargain")
	float ActiveAttackSpeedMultiplier = 1.0f;
};
