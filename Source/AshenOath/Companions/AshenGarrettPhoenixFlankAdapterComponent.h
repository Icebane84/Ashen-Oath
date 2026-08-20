// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettPhoenixFlankAdapterComponent.generated.h"

/**
 * UAshenGarrettPhoenixFlankAdapterComponent
 * Companion component executing Garrett's sovereign Phoenix flank assassination strikes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettPhoenixFlankAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettPhoenixFlankAdapterComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float PhoenixFlankMultiplier = 2.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	bool ExecutePhoenixFlankStrike(AActor* TargetEnemy);
};
