// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettFlankDistractionAdapterComponent.generated.h"

/**
 * UAshenGarrettFlankDistractionAdapterComponent
 * Companion component executing Garrett's tactical flank distraction maneuvers based on target threat scoring.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettFlankDistractionAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettFlankDistractionAdapterComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float DistractionThreatMultiplier = 1.75f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	bool ExecuteFlankDistractionManeuver(AActor* TargetEnemy);
};
