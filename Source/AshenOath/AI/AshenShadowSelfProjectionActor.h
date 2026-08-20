// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenShadowSelfProjectionActor.generated.h"

/**
 * AAshenShadowSelfProjectionActor
 * Psychic entity manifestation actor representing The Shadow Self in Oathbringer's Inner World (formless darkness, distorted reflection, whispers).
 */
UCLASS()
class ASHENOATH_API AAshenShadowSelfProjectionActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenShadowSelfProjectionActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Inner World")
	float ShadowWhisperVolume = 0.95f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Inner World")
	bool TriggerShadowSelfGaslightingWhispers();
};
