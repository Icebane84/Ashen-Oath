// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSanctuaryHearthEmbersResonanceActor.generated.h"

/**
 * AAshenSanctuaryHearthEmbersResonanceActor
 * World actor driving Sanctuary campfire ember particle density during SLM compilation.
 */
UCLASS()
class ASHENOATH_API AAshenSanctuaryHearthEmbersResonanceActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanctuaryHearthEmbersResonanceActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetEmberSpawnRateScalar() const { return EmberSpawnRateScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float EmberSpawnRateScalar = 1.0f;
};
