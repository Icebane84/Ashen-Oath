// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenResonanceSyncVisualFlourishActor.generated.h"

/**
 * AAshenResonanceSyncVisualFlourishActor
 * World actor driving Oathbringer visual flourish, golden ember particle burst, and camera bloom when ResonanceSync is active.
 */
UCLASS()
class ASHENOATH_API AAshenResonanceSyncVisualFlourishActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenResonanceSyncVisualFlourishActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Visuals")
	float FlourishDurationSeconds = 15.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void TriggerResonanceSyncFlourish();
};
