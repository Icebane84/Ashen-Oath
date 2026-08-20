// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCrisisTypes.h"
#include "AshenStaggeredCrisisTimelineController.generated.h"

/**
 * UAshenStaggeredCrisisTimelineController
 * Controller orchestrating the 2.0-second staggered crisis timeline during temporal dilation events.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStaggeredCrisisTimelineController : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenStaggeredCrisisTimelineController();

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Crisis")
	FOnCrisisStageShifted OnCrisisStageShifted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Crisis")
	EAshenCrisisStage CurrentCrisisStage = EAshenCrisisStage::Inactive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Crisis")
	float TimeDilationScalar = 0.10f; // 10% Speed

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crisis")
	void InitiateCrisisTimeline();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crisis")
	void ProgressToCrisisStage(EAshenCrisisStage NewStage);
};
