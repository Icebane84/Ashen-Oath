// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMiasmaExposureComponent.generated.h"

/**
 * UAshenMiasmaExposureComponent
 * Evaluates player toxicity accumulation, respirator mask filter degradation (0.05/s), and hazardous environmental tick damage (12.0 DMG/s).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMiasmaExposureComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMiasmaExposureComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Hazard")
	float FilterIntegrity = 1.0f; // 1.0 to 0.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Hazard")
	float FilterDegradationRate = 0.05f; // per second

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Hazard")
	float BaseToxicityDamagePerSecond = 12.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Hazard")
	float CalculateExposureDamage(float DeltaSeconds, float AtmosphericToxicity);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Hazard")
	void RestoreFilter(float Amount);
};
