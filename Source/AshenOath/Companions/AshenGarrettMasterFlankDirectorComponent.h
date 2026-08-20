// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettMasterFlankDirectorComponent.generated.h"

/**
 * UAshenGarrettMasterFlankDirectorComponent
 * Companion component directing Garrett's pinnacle master flank positioning.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettMasterFlankDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettMasterFlankDirectorComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float MasterFlankRadius = 650.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	bool DirectMasterFlankStrike(AActor* TargetEnemy);
};
