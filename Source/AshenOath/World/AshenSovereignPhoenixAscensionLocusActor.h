// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSovereignPhoenixAscensionLocusActor.generated.h"

/**
 * AAshenSovereignPhoenixAscensionLocusActor
 * Epic landmark world actor representing the Sovereign Phoenix Crucible at Blackwood Peak summit, emitting white flame embers and state vector luminescence.
 */
UCLASS()
class ASHENOATH_API AAshenSovereignPhoenixAscensionLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSovereignPhoenixAscensionLocusActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sovereign Phoenix")
	float WhiteFlameLuminescenceIntensity = 2.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sovereign Phoenix")
	bool bSovereignLocusConsecrated = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Sovereign Phoenix")
	void TriggerPhoenixAscensionPulse();
};
