// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AshenAshenAbominationBossActor.generated.h"

/**
 * AAshenAshenAbominationBossActor
 * 3D Apex boss actor executing the Blackwood Bridge multi-ton overhead crush and arguing the thesis "Sacrifice is Selfish".
 */
UCLASS()
class ASHENOATH_API AAshenAshenAbominationBossActor : public ACharacter
{
	GENERATED_BODY()
public:
	AAshenAshenAbominationBossActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss")
	float MaxStaggerThreshold = 1500.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Boss")
	bool bIsDorsalVentExposed = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	void ExposeDorsalVent();
};
