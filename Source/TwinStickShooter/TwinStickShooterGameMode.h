#pragma once

#include "GameFramework/GameMode.h"
#include "Net/UnrealNetwork.h"
#include "TwinStickShooterGameMode.generated.h"


UCLASS(minimalapi)
class ATwinStickShooterGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ATwinStickShooterGameMode();

	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

};



