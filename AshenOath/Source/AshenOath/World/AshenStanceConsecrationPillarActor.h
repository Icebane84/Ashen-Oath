// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenCombatStanceTypes.h"
#include "AshenStanceConsecrationPillarActor.generated.h"

/**
 * AAshenStanceConsecrationPillarActor
 * World pillar actor in combat arenas allowing Kaelen to consecrate and awaken latent stance masteries.
 */
UCLASS()
class ASHENOATH_API AAshenStanceConsecrationPillarActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenStanceConsecrationPillarActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	ECombatStance ConsecratedStance = ECombatStance::Flow;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	bool bIsConsecrated = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ConsecratePillar(AActor* InstigatingPlayer);
};
