// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenHeartstoneDebtPurificationLocus.generated.h"

/**
 * AAshenHeartstoneDebtPurificationLocus
 * World actor locus processing Heartstone ritual debt clearance and state vector stabilization.
 */
UCLASS()
class ASHENOATH_API AAshenHeartstoneDebtPurificationLocus : public AActor
{
	GENERATED_BODY()
public:
	AAshenHeartstoneDebtPurificationLocus();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | World")
	float PurificationRadius = 500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	bool PerformDebtPurificationRitual();
};
