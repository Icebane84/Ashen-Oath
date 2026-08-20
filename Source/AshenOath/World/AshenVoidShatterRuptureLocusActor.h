// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenVoidShatterRuptureLocusActor.generated.h"

/**
 * AAshenVoidShatterRuptureLocusActor
 * In-world physical actor marking ground rupture fissures and lingering void miasma.
 */
UCLASS()
class ASHENOATH_API AAshenVoidShatterRuptureLocusActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenVoidShatterRuptureLocusActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float RuptureLifetime = 6.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void DissolveRuptureLocus();
};
