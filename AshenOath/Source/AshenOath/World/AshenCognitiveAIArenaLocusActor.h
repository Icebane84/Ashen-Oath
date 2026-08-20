// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenCognitiveAIArenaLocusActor.generated.h"

/**
 * AAshenCognitiveAIArenaLocusActor
 * Physical world locus actor defining AI tactical range arenas and multi-target threat perception boundaries.
 */
UCLASS()
class ASHENOATH_API AAshenCognitiveAIArenaLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenCognitiveAIArenaLocusActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Arena")
	float ArenaTacticalRadius = 1500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Arena")
	bool IsTargetWithinArenaBounds(FVector TargetLocation) const;
};
