// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenNightmareRiftActor.generated.h"

/**
 * AAshenNightmareRiftActor
 * Spatial tear in reality emitting 800uu corruption pulses and requiring psychic channeling to seal.
 */
UCLASS()
class ASHENOATH_API AAshenNightmareRiftActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenNightmareRiftActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nightmare")
	float RiftPulseRadius = 800.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Nightmare")
	bool bIsRiftSealed = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nightmare")
	bool SealRift(AActor* InstigatingPlayer);
};
