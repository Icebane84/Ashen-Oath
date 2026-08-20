// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTrinityDoctrineCompanionSynergyComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTrinitySynergyTriggeredSignature, FName, CompanionID, FName, SynergyActionTag, float, EfficiencyMultiplier);

/**
 * UAshenTrinityDoctrineCompanionSynergyComponent
 *
 * Component driving Garrett Tactical Flank Intercepts & Serafina Harmonic Purification (The Trinity Doctrine, PRS-001 Combat Blueprint).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTrinityDoctrineCompanionSynergyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTrinityDoctrineCompanionSynergyComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|TrinityDoctrine")
	void TriggerCompanionSynergy(FName CompanionID, bool bIsKaelenUnbroken);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TrinityDoctrine|Events")
	FOnTrinitySynergyTriggeredSignature OnSynergyTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|TrinityDoctrine")
	int32 TotalSynergiesExecuted = 0;
};
