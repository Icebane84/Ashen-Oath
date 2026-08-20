// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSovereignPhoenixAscensionMonumentActor.generated.h"

/**
 * AAshenSovereignPhoenixAscensionMonumentActor
 * Physical world monument actor commemorating Grand Master Milestone 1100 Sovereign Phoenix Ascension.
 */
UCLASS()
class ASHENOATH_API AAshenSovereignPhoenixAscensionMonumentActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSovereignPhoenixAscensionMonumentActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sovereign")
	float SovereignAscensionRadius = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sovereign")
	bool bMonumentActive = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Sovereign")
	bool ActivateSovereignPhoenixMonument();
};
