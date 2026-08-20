// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenCombatPsychologicalFeedBroadcaster.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCombatPsychologicalStateBroadcastedSignature, FName, ActiveStanceTag, FName, WillpowerTag, float, PartyTrustLevel);

/**
 * UAshenCombatPsychologicalFeedBroadcaster
 *
 * Subsystem broadcasting real-time combat stance & willpower state updates to UI/Audio/AI (PRS-001 Combat Blueprint).
 */
UCLASS()
class ASHENOATH_API UAshenCombatPsychologicalFeedBroadcaster : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CombatFeedBroadcaster")
	void BroadcastCombatPsychologicalState(FName StanceTag, FName WillpowerTag, float TrustLevel);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CombatFeedBroadcaster|Events")
	FOnCombatPsychologicalStateBroadcastedSignature OnCombatFeedBroadcasted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CombatFeedBroadcaster")
	int32 TotalFeedBroadcastsSent = 0;
};
