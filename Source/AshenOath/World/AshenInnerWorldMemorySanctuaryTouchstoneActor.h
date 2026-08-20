// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenInnerWorldMemorySanctuaryTouchstoneActor.generated.h"

/**
 * AAshenInnerWorldMemorySanctuaryTouchstoneActor
 * Interactive world touchstone actor allowing Kaelen to initiate meditation to access Oathbringer's Inner World.
 */
UCLASS()
class ASHENOATH_API AAshenInnerWorldMemorySanctuaryTouchstoneActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenInnerWorldMemorySanctuaryTouchstoneActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Touchstone")
	float MeditationChimeFrequency = 440.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Touchstone")
	bool InitiateInnerWorldMeditation();
};
