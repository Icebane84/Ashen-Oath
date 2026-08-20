// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaTransferenceComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTransferencePulse, float, HealingTransferred, float, BurnoutAccrued);

/**
 * UAshenSerafinaTransferenceComponent
 * Siphons Kaelen's corruption into Serafina using exponential Nyx toll math:
 * Toll = RawHealing * (1.0 + (e^Corruption - 1.0))
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaTransferenceComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSerafinaTransferenceComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Transference")
	FOnTransferencePulse OnTransferencePulse;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Transference")
	bool bIsChannelingActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Transference")
	float CalculateTransferenceToll(float RawHealingAmount, float KaelenCorruption) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Transference")
	bool ExecuteTransferencePulse(float HealingAmount, float KaelenCorruption);
};
