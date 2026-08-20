// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenJournalMapDistortionAdapter.generated.h"

/**
 * UAshenJournalMapDistortionAdapter
 * Modulates World Map UI post-process with mud desaturation vignette and route chromatic aberration under Guarded Friction.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalMapDistortionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenJournalMapDistortionAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Map")
	float MapChromaticAberrationIntensity = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Map")
	float MapMudVignetteIntensity = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Map")
	void UpdateMapDistortionForFriction(bool bGuardedFriction, float DebtLevel);
};
