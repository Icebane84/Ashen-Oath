// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AshenVeilHoundStalkerActor.generated.h"

/**
 * AAshenVeilHoundStalkerActor
 * Tier II Trauma predator exploiting Kaelen's hunched blindspots and testing the unit's flank coherence.
 */
UCLASS()
class ASHENOATH_API AAshenVeilHoundStalkerActor : public ACharacter
{
	GENERATED_BODY()
public:
	AAshenVeilHoundStalkerActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Stalker")
	float StalkingSpeed = 550.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Stalker")
	bool AttemptFlankAmbush(AActor* TargetHero, bool bHeroIsHunched);
};
