// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenSoulConstellationHeartstoneLocusActor.generated.h"

/**
 * AAshenSoulConstellationHeartstoneLocusActor
 * World actor representing the Heartstone ritual locus where Kaelen invokes CompileIdentity().
 * Acts as the physical anchor point for identity compilation and imprint buffer flush rituals.
 */
UCLASS()
class ASHENOATH_API AAshenSoulConstellationHeartstoneLocusActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenSoulConstellationHeartstoneLocusActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | World")
	float HeartstoneResonanceRadius = 600.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	bool TriggerHeartstoneIdentityCompilation();
};
