// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenDevilsBargainTrustAtrophyDirector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTrustAtrophyAppliedSignature, float, ActiveTrustLevel, float, CompanionComboDelaySeconds, float, HealingDelaySeconds);

/**
 * UAshenDevilsBargainTrustAtrophyDirector
 *
 * Director applying Party Trust Atrophy and delaying Serafina's healing logic during Stance.UnchainedBerserk (PRS-001 Combat Blueprint).
 */
UCLASS()
class ASHENOATH_API UAshenDevilsBargainTrustAtrophyDirector : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|TrustAtrophy")
	void ApplyDevilsBargainTrustAtrophy(float AtrophyAmount = 25.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TrustAtrophy|Events")
	FOnTrustAtrophyAppliedSignature OnTrustAtrophyApplied;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|TrustAtrophy")
	float ActivePartyTrustLevel = 100.0f;
};
