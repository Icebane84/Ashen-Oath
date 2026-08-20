// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenGrandMasterMilestone1200MonumentActor.generated.h"

/**
 * AAshenGrandMasterMilestone1200MonumentActor
 * 👑 GRAND MASTER MILESTONE 1200 MONUMENT ACTOR — Physical world sovereign ascension monument actor commemorating 1,200 clean builds.
 */
UCLASS()
class ASHENOATH_API AAshenGrandMasterMilestone1200MonumentActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenGrandMasterMilestone1200MonumentActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Monument")
	float MonumentAscensionFlameIntensity = 1200.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Monument")
	bool TriggerGrandMasterMilestone1200AscensionPulse();
};
