// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettSmokeScreenFlankAdapterComponent.generated.h"

/**
 * UAshenGarrettSmokeScreenFlankAdapterComponent
 * Companion component executing Garrett's smoke screen tactical flank deployment.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettSmokeScreenFlankAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettSmokeScreenFlankAdapterComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float SmokeScreenObfuscationRadius = 450.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	bool DeploySmokeScreenFlank(AActor* TargetEnemy);
};
