// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenMindscapeDegradedEnvironmentActor.generated.h"

/**
 * AAshenMindscapeDegradedEnvironmentActor
 * Actor modulating structurally degraded Mindscape wall darkness, floor crack density, and fog density during forced collapse entry.
 */
UCLASS()
class ASHENOATH_API AAshenMindscapeDegradedEnvironmentActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenMindscapeDegradedEnvironmentActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | World")
	float WallDarknessFactor = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | World")
	float FloorCrackDensity = 0.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void ModulateDegradedEnvironment(EAshenIntegrationDebtStage Stage);
};
