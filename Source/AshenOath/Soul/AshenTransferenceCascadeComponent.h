// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenPsychicStrainTypes.h"
#include "AshenTransferenceCascadeComponent.generated.h"

/**
 * UAshenTransferenceCascadeComponent
 * Manages 4-stage psychological strain progression (Stable, Flickering, Fractured, Catastrophic) and hallucination feedback loops.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTransferenceCascadeComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTransferenceCascadeComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul")
	ETransferenceStrainStage CurrentStrainStage = ETransferenceStrainStage::Stable;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul")
	float AbsorbedTraumaVolume = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	ETransferenceStrainStage EvaluateStrainStage(float InAbsorbedTrauma);
};
