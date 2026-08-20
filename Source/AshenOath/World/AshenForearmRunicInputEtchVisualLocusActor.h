// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenForearmRunicInputEtchVisualLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnForearmRunicInputEtchedSignature, FVector, ForearmLocation, float, PulseIntensity);

/**
 * AAshenForearmRunicInputEtchVisualLocusActor
 *
 * World Actor rendering etched in-world trigger inputs (LT+RT / L2+R2) pulsing along Kaelen's forearm veins (PRS-001-UI-006).
 */
UCLASS()
class ASHENOATH_API AAshenForearmRunicInputEtchVisualLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenForearmRunicInputEtchVisualLocusActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ForearmRunicInput")
	void TriggerForearmRunicInputEtch(float Intensity = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ForearmRunicInput|Events")
	FOnForearmRunicInputEtchedSignature OnRunicInputEtched;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ForearmRunicInput")
	bool bIsInputEtched = false;
};
