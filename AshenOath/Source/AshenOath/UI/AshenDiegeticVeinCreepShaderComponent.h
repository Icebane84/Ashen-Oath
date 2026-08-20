// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticVeinCreepShaderComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVeinCreepProgressUpdatedSignature, float, VeinCoveragePercent, float, PulseFrequency);

/**
 * UAshenDiegeticVeinCreepShaderComponent
 *
 * Component animating diegetic black vein tendrils crawling inward like ocular pressure artifacts (PRS-001-UI-006).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticVeinCreepShaderComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticVeinCreepShaderComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VeinCreepShader")
	void UpdateVeinCreepCoverage(float ProgressNormalized);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VeinCreepShader|Events")
	FOnVeinCreepProgressUpdatedSignature OnVeinCreepUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|VeinCreepShader")
	float ActiveVeinCoverage = 0.0f;
};
