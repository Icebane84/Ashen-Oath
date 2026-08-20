// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenJournalHandwritingMorphComponent.generated.h"

/**
 * UAshenJournalHandwritingMorphComponent
 * Computes procedural font jitter, line wave perturbation, and pen pressure tearing based on IntegrationDebt.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalHandwritingMorphComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenJournalHandwritingMorphComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Journal")
	float LetterJitterFrequency = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Journal")
	float PenPressureScale = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Journal")
	void CalculateHandwritingDegradation(float KaelenDebt);
};
