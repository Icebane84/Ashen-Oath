// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathbringerResonanceTuningComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResonanceTunedSignature, int32, UpgradeLevel, float, AegisReflectionPower);

/**
 * UAshenOathbringerResonanceTuningComponent
 *
 * Component enabling Aegis Reflection and physical upgrade tuning for Oathbringer Greatsword (PRS-001 Combat Blueprint).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerResonanceTuningComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerResonanceTuningComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ResonanceTuning")
	void ApplyResonanceTuning(int32 AdditionalUpgrades);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ResonanceTuning|Events")
	FOnResonanceTunedSignature OnResonanceTuned;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ResonanceTuning")
	int32 ActiveUpgradeLevel = 1;
};
