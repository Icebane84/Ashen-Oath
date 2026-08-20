// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenHeartstoneSanctuaryLocusActor.generated.h"

/**
 * AAshenHeartstoneSanctuaryLocusActor
 * Physical world locus actor providing Heartstone Sanctuary ambient floating ash and white flame visual aura.
 */
UCLASS()
class ASHENOATH_API AAshenHeartstoneSanctuaryLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenHeartstoneSanctuaryLocusActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sanctuary")
	float WhiteFlameAuraIntensity = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Sanctuary")
	bool TriggerSanctuaryFlameAuraPulse();
};
