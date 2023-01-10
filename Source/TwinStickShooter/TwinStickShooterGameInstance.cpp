#include "TwinStickShooterGameInstance.h"

void UTwinStickShooterGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr))
		return;

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr))
		return;

	World->ServerTravel("TwinStickExampleMap?listen");
}

void UTwinStickShooterGameInstance::Join(const FString& Adress)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr))
		return;
	
	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if (!ensure(PlayerController != nullptr))
		return;

	PlayerController->ClientTravel(Adress, ETravelType::TRAVEL_Absolute);
}