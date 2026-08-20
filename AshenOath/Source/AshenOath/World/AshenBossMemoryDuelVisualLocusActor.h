// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenBossMemoryDuelVisualLocusActor.generated.h"

/**
 * AAshenBossMemoryDuelVisualLocusActor
 * Central hovering memory locus casting radial light rays during boss transitions.
 */
UCLASS()
class ASHENOATH_API AAshenBossMemoryDuelVisualLocusActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenBossMemoryDuelVisualLocusActor();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void TriggerRadialMemoryBeams();
};
