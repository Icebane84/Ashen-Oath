// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenImprintBufferComponent.generated.h"

/**
 * UAshenImprintBufferComponent
 * ENGINE-SPEC-001 contiguous imprint buffer — TArray<FAshenPsychologicalImprint> pre-reserved to 64 entries.
 * AddImprint() accumulates weight deltas and feeds them to USoulConstellationSubsystem.ApplyRawWeightDeltas().
 * Call FlushToKernel() to push the batch to the kernel and clear the buffer.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenImprintBufferComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenImprintBufferComponent();
	virtual void BeginPlay() override;

	/** Add a single psychological imprint event to the contiguous buffer */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void AddImprint(FAshenPsychologicalImprint Imprint);

	/** Push all buffered imprint deltas to the SoulConstellationSubsystem kernel and clear the buffer */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void FlushToKernel();

	/** Total accumulated IntegrationDebt pending flush */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	float GetPendingDebtAccumulation() const;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul")
	int32 BufferedImprintCount = 0;

private:
	TArray<FAshenPsychologicalImprint> ImprintBuffer;
};
