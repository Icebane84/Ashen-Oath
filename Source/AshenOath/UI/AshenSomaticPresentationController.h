// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticPresentationController.generated.h"

/**
 * UAshenSomaticPresentationController
 * Controller updating journal parchment visual distortion, ink bleed, and handwriting wobble based on Kaelen's sanity and physical trauma.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticPresentationController : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticPresentationController();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | UI")
	float InkBleedScalar = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | UI")
	float HandwritingWobbleIntensity = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | UI")
	float CalculatedHandwritingWobble = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateSomaticPresentation(float Sanity, float Corruption);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void EvaluateSomaticPresentation(float PhysicalExhaustion, float MentalTrauma, float EnvironmentalCorruption);
};
