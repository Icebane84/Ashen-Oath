// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenHarmonicResonancePitchComponent.generated.h"

/**
 * UAshenHarmonicResonancePitchComponent
 * Modulates audio frequency pitch (220Hz root A3 up to 880Hz A5) for vibrating light filaments based on companion trust and resonance.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHarmonicResonancePitchComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenHarmonicResonancePitchComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Audio")
	float FilamentPitchFrequencyHz = 440.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateFilamentPitch(float TrustScalar, float DebtScalar);
};
