// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTripartiteFatigueBurnComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionVulnerabilityTriggered, FName, CompanionID, float, FatigueLevel);

/**
 * UAshenTripartiteFatigueBurnComponent
 * Component tracking Control (Garrett), Emotional Poise (Serafina), and Transference (Kaelen) fatigue; triggers Vulnerable state at > 0.7f.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteFatigueBurnComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTripartiteFatigueBurnComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Companions")
	FOnCompanionVulnerabilityTriggered OnVulnerabilityTriggered;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companions")
	float GarrettControlFatigue = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companions")
	float SerafinaPoiseFatigue = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companions")
	float KaelenTransferenceFatigue = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void AccumulateFatigue(float GarrettDelta, float SerafinaDelta, float KaelenDelta);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Companions")
	bool IsCompanionVulnerable(FName CompanionID) const;
};
