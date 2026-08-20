// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSovereignPhoenixShrineActor.generated.h"

/**
 * AAshenSovereignPhoenixShrineActor
 * Interactive world shrine actor enabling sovereign Phoenix ascension resting, perk unlocking, and white flame blessing.
 */
UCLASS()
class ASHENOATH_API AAshenSovereignPhoenixShrineActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSovereignPhoenixShrineActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sovereign Phoenix")
	float ShrineSanctuaryRadius = 900.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sovereign Phoenix")
	bool bShrineActive = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Sovereign Phoenix")
	bool InitiateSovereignPhoenixRest(AActor* InstigatorActor);
};
