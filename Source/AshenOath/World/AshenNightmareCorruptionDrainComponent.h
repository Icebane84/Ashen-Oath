// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNightmareCorruptionDrainComponent.generated.h"

/**
 * UAshenNightmareCorruptionDrainComponent
 * Manages localized corruption siphoning and sanctuary rift suppression calculations.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNightmareCorruptionDrainComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNightmareCorruptionDrainComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nightmare")
	float DrainRatePerSecond = 0.08f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nightmare")
	float SiphonCorruption(float DeltaSeconds, float CurrentIntensity) const;
};
