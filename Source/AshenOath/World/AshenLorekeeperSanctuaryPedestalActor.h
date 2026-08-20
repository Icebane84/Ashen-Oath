// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenLorekeeperSanctuaryPedestalActor.generated.h"

/**
 * AAshenLorekeeperSanctuaryPedestalActor
 * Sanctuary pedestal securing ancient scrolls and unlocking realm history dialogue prompts.
 */
UCLASS()
class ASHENOATH_API AAshenLorekeeperSanctuaryPedestalActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenLorekeeperSanctuaryPedestalActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Codex")
	FName SecuredRelicID = NAME_None;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Codex")
	bool bIsRelicRestored = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Codex")
	bool RestoreRelic(AActor* InstigatingPlayer);
};
