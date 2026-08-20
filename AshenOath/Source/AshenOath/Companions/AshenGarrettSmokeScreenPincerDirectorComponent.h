// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettSmokeScreenPincerDirectorComponent.generated.h"

/**
 * UAshenGarrettSmokeScreenPincerDirectorComponent
 * Companion component directing Garrett's smoke screen relational pincer tactical maneuvers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettSmokeScreenPincerDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettSmokeScreenPincerDirectorComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float SmokeScreenPincerRadius = 600.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	bool DirectSmokeScreenPincer(AActor* TargetEnemy);
};
